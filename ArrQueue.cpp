// Copyright 2023 || Elton Soares

#include<iostream>

class ArrQueue{
public:
  ArrQueue();
  ArrQueue(ArrQueue &&) = default;
  ArrQueue(const ArrQueue &) = default;
  ArrQueue &operator=(ArrQueue &&) = default;
  ArrQueue &operator=(const ArrQueue &) = default;
  ~ArrQueue();

private:
  
};

ArrQueue::ArrQueue() {
}

ArrQueue::~ArrQueue() {
}
