/*
 *  Copyright (c) 2021 Thakee Nathees
 *  Licensed under: MIT License
 */

#ifndef CORE_H
#define CORE_H

#include "var.h"
#include "common.h"

// Initialize core language, builtin function and core libs.
void initializeCore(PKVM* vm);

// Find the builtin function name and returns it's index in the builtins array
// if not found returns -1.
int findBuiltinFunction(PKVM* vm, const char* name, uint32_t length);

// Returns the builtin function at index [index].
Function* getBuiltinFunction(PKVM* vm, int index);

// Returns the builtin function's name at index [index].
const char* getBuiltinFunctionName(PKVM* vm, int index);

// Return the core library with the [name] if exists in the core libs,
// otherwise returns NULL.
Script* getCoreLib(PKVM* vm, String* name);

// Operators //////////////////////////////////////////////////////////////////

Var varAdd(PKVM* vm, Var v1, Var v2);
Var varSubtract(PKVM* vm, Var v1, Var v2);
Var varMultiply(PKVM* vm, Var v1, Var v2);
Var varDivide(PKVM* vm, Var v1, Var v2);
Var varModulo(PKVM* vm, Var v1, Var v2);

bool varGreater(PKVM* vm, Var v1, Var v2);
bool varLesser(PKVM* vm, Var v1, Var v2);

Var varGetAttrib(PKVM* vm, Var on, String* attrib);
void varSetAttrib(PKVM* vm, Var on, String* name, Var value);

Var varGetSubscript(PKVM* vm, Var on, Var key);
void varsetSubscript(PKVM* vm, Var on, Var key, Var value);

// Functions //////////////////////////////////////////////////////////////////

// Parameter [iterator] should be VAR_NULL before starting the iteration.
// If an element is obtained by iteration it'll return true otherwise returns
// false indicating that the iteration is over.
bool varIterate(PKVM* vm, Var seq, Var* iterator, Var* value);

#endif // CORE_H