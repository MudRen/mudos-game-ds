inherit ITEM;

void create()
{
        set_name("�Ů����", ({"blue-boat ticket", "ticket","_OBJECT_DTL2_BOAT_TICKET_" }));
        set_weight(10);
        if( !clonep() ) {
                set("unit", "�i");
                set("value", 800);
                set("long", "�o�O�@�i�ѡu������v�}���u�n���ԡv����C\n");
        }
        setup();
}


