#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIR"�p���󭻼Q�Q���ǭ��n-������"NOR,({ "sexking head","head" }) );
        set("long",@LONG
�o�O�@�󭻼Q�Q�����ǡA�i�H���b�Y�W�]�i��b�Ǥl�̡C
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "��");
        set("value",0);
        set("volume", 4);
        set("max_lv",50);
        set("limit_lv",1);
      set("armor_prop/str",60);
      set("armor_prop/con",150);
set("armor_prop/armor",5000);;set("armor_prop/show_damage",1);
set("wear_msg","$N�q�ѤW�l��@�F�@��$n���U�ӡA���Q�Q���N$n�����y�W�A�@�ƺ������ˤl��C�C\n");
set("rem_msg", "$N�N$n�q�y�W�K�U�ӡA�B���ѧl�@�l���������A���A�n������C\n");

}
 setup();
}
int query_autoload() { return 1; }
void init()
{
  object me=this_player();
  if(!wizardp(me))
{
  destruct(this_object());
  message_vision("$N�n���_�ɤ��Ǭ�M�ĤƤF!\n",me);
  message_vision("��̫�w�����L��!\n",me);
} 

}

