inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�s����", ({ "water box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӥΨӦs��������l�C\n");
                set("unit", "�~");
                  set("value", 40);       
                  set("heal_ap",5);      
                   set("water_remaining", 5);
          set("drink_msg","$N���}���l���\\�l�A�M��ܤF�X�f�C\n");
        set("finish_drink_msg","$N�N���l�̾l�U�����ܥ��F�C\n");
        }
}
