inherit ITEM;
inherit F_WATER;
void create()
{
     set_name("�t��", ({ "water" }) );
     set_weight(100);
     if( clonep() )
         set_default_object(__FILE__);
     else {
         set("long", "�@�~���o�X�]�O���~�l�C\n");
         set("unit", "�~");
         set("value", 16);
         set("heal_mp",1);
         set("water_remaining", 3);
         }
setup();
}

