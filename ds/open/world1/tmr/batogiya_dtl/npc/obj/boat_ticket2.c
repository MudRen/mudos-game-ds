inherit ITEM;

void create()
{
        set_name("藍海號船票", ({"blue-boat ticket", "ticket","_OBJECT_DTL2_BOAT_TICKET_" }));
        set_weight(10);
        if( !clonep() ) {
                set("unit", "張");
                set("value", 800);
                set("long", "這是一張由「杜尼港」開往「登托拉」的船票。\n");
        }
        setup();
}


