//
// Created by Narek Abovyan on 23.02.2022.
//

#ifndef TON_COMMON_H
#define TON_COMMON_H

#include "vm/vm.h"
#include "vm/cp0.h"
#include "vm/boc.h"
#include "vm/stack.hpp"
#include "crypto/block/block.h"
#include "td/utils/base64.h"
#include "td/utils/ScopeGuard.h"
#include "terminal/terminal.h"
#include "td/utils/Random.h"
#include "td/utils/filesystem.h"
#include "td/utils/JsonBuilder.h"
#include "td/utils/OptionParser.h"
#include "td/utils/logging.h"
#include "StringLog.h"
#include <sstream>
#include <iomanip>


std::string escape_json(const std::string &s);

td::Ref<vm::Tuple> prepare_vm_c7(ton::UnixTime now);

td::Result<vm::StackEntry> json_to_stack_entry(td::JsonObject &obj);

td::Result<td::Ref<vm::Stack>> json_to_stack(td::JsonArray &array);

td::Result<std::string> stack_entry_to_json(vm::StackEntry se);

td::Result<std::string> stack2json(vm::Ref<vm::Stack> stack);

td::Result<std::string> run_vm(td::Ref<vm::Cell> code_cell, td::Ref<vm::Cell> data, td::JsonArray &stack_array, td::JsonObject &c7_register,
                   int function_selector, std::function<std::string()> getLogs);

td::Result<std::string> vm_exec_from_config(std::string config, std::function<std::string()> getLogs);

#endif  //TON_COMMON_H
