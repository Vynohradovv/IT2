#pragma once

int isStackEmpty(void);
int isStackFull(void);
int Pop(void);
int Top(void);
void Push(int val);

bool StackInit(int size);
void StackDeinit(void);