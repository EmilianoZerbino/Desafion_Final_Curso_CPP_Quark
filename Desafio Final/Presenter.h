#pragma once

#include "Store.h"
#include "View.h"

class Presenter
{
public:

    Presenter(Store& store, View& view);
    void execute();

private:

    Store& store;
    View& view;

};
