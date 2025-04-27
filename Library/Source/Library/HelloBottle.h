#pragma once

#include <string>
#include <memory>

class HelloBottle
{
  public:
    HelloBottle();
    virtual ~HelloBottle();

    void exportBottle(const std::string& filename);
    void makeBottle();
    void investigateBottle();

  private:
    class pimpl;
    std::unique_ptr<pimpl> p;
};