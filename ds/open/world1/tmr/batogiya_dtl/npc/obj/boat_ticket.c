inherit ITEM;

void create()
{
        set_name("�Ů����", ({"blue-boat ticket", "ticket","_OBJECT_DTL_BOAT_TICKET_" }));
        set_weight(10);
        if( !clonep() ) {
                set("unit", "�i");
                set("value", 500);
                set("long", "�o�O�@�i�ѡu�n���ԡv�}���u������v����C\n");
        }
        setup();
}


