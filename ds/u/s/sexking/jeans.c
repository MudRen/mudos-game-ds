#include <armor.h>
inherit PANTS;

void create()
{
        set_name("����p����",({ "sexking jeans","jeans" }) );
        set("long",@LONG
�o�O�@��ܺ}�G������,�b���Ѫ������٦��X������C
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "��");
        set("value",100000);
        set("volume", 4);
        set("max_lv",50);
        set("limit_lv",1);
      set("armor_prop/str",60);
      set("armor_prop/con",150);
set("armor_prop/armor",5000);;set("armor_prop/show_damage",1);
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

