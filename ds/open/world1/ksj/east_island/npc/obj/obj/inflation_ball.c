#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"���Ȥ��y"NOR,({"inflation ball","ball"}));
        set("long","�@�����j���y�A�̭��n���˵ۤ��S���������F��A�����D�n�F����(useit)�C\n");
        set("unit","��"); 
        set_weight(1000);
        set("no_give",1);
        set("no_sac",1);
        setup();
}
int init(string arg)
{
   if(this_player()->is_busy()) return 0;
   add_action("do_useit","useit"); 
}
int do_useit(string agg)
{
   object me=this_player();
   if(agg != "inflation") return notify_fail("�A�n�F����?(inflation)\n"); 
   {
   message_vision(HIW"$N�N���y�����|�_�A��M��$N�����ܪ������ƪ�....\n"NOR,me);
   me->set_temp("be_inflation",1); 
   } 
   return 1;
}
int query_autoload() { return 1; }

