#include "vm/cp0.h"
#include "td/utils/logging.h"
#include "StringLog.h"
#include "common.h"

using namespace std::literals::string_literals;

auto memLog = new StringLog();

extern "C" char *vm_exec(int len, char *_data) {
  // Init logging
  td::log_interface = memLog;
  SET_VERBOSITY_LEVEL(verbosity_DEBUG);

  std::string config(_data, len);

  auto res = vm_exec_from_config(config, []() -> std::string { return memLog->get_string(); });

  if (res.is_error()) {
    std::string result;
    result += "{";
    result +=  R"("ok": false,)";
    result +=  R"("error": ")" + escape_json(res.move_as_error().message().str()) + R"(")";
    result += "}";

    return strdup(result.c_str());
  }
  return strdup(res.move_as_ok().c_str());
}