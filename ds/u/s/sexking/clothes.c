#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�p������",({"sexking clothes","clothes"}) );
        set("long",@LONG
   �o�O�@��Ц��p����лx����A�A�O�ɤU�̬y�檺�ڦ��C
LONG);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",201);
        setup();
        set("value",100000);
        set("volume", 4);
        set("armor_prop/int",75);
        set("armor_prop/dex",90);
        set("armor_prop/con",10);
}
int query_autoload() { return 1; } 
void init()
{
  object me=this_player();
  if(!wizardp(me))
{
  destruct(this_object());
  message_vision("$N�n���_�ɦ�ˬ�M�z���F!\n",me);
  message_vision("$N�~���N�����y!\n",me);
} 

}

