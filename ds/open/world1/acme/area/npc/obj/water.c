inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�ѭ����S", ({ "sky water","water" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�o�O�@�~�u���b�ѭ��ȴ̤~�R�o�쪺�ѭ����S�A�������������ĥΡC\n");
                set("unit", "�~");
                 set("value",54);
           set("heal_hp",8);
              set("heal_mp",10);
                set("water_remaining", 3);
        }
     setup();
}
