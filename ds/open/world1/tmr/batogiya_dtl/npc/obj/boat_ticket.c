inherit ITEM;

void create()
{
        set_name("藍海號船票", ({"blue-boat ticket", "ticket","_OBJECT_DTL_BOAT_TICKET_" }));
        set_weight(10);
        if( !clonep() ) {
                set("unit", "張");
                set("value", 500);
                set("long", "這是一張由「登托拉」開往「杜尼港」的船票。\n");
        }
        setup();
}


