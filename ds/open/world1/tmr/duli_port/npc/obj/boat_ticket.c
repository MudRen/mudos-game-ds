inherit ITEM;

void create()
{
        set_name("船票", ({"boat ticket", "ticket","_OBJECT_DULI_BOAT_TICKET_" }));
        set_weight(10);
        if( !clonep() ) {
                set("unit", "張");
                  set("value", 200);
set("long", "這是一張由杜尼港開往「鯨魚島」的船票。\n");
        }
        setup();
}

