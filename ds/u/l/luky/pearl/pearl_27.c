// Room: /u/l/luky/room/pearl_27.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "[1;32m�����q�K���j�U[m");
set("long", @LONG

����  �ġġġġ�
���y�Ģj�Ⲽ�B�y���ġ�  �o�̬O�����q�K�����j�U�C�J�f��
���y :�j�i�i�i�y�i      �䦳�ӰⲼ�B�A�Ѯȫ��ʲ�(buy)
���y :�j�i�i�i�y�i      �ΡC�o�̪������H�ܦh�A�A�̦n�p
���y :�j      �y�i      �ߤ@�I�A�H�K�Q����ݤW�C
���y :�j      �y���á�
���y�ááááá�
����

LONG
	);
set("objects",([
__DIR__"npc/sightseer":2,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_32",
"east" : __DIR__"pearl_26",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="west")
 {
  if(!wizardp(me))
  {
   if(!this_player()->query_temp("ticket")) return notify_fail("�A�S���R������i�h�C\n");
   write(HIW"�A�Ⲽ����������K����x���h�C\n"NOR);
   me->delete_temp("ticket");
   return ::valid_leave(me, dir);
  } else 
   {
    message_vision("[1;35m$N[1;37m�����ﯸ����: �ڬO�Ův... ���ζR���F�a..[m\n",this_player());
    message_vision("[0;36m�����I�F�I�Y.. ��$N[0;36m�L�h�F..[m\n",this_player());
    return ::valid_leave(me, dir);
   }
 }
 return ::valid_leave(me, dir);
}

void init()
{
add_action("do_buy", "buy");
}

int do_buy(string arg)
{
 object me;
 me=this_player();
 if(!arg) return notify_fail("�A�n�R����??\n");
 if(arg=="ticket")
 { 
  if(me->query_temp("ticket")) return notify_fail("�A�w�g�R�L���F�C\n");
  if(this_player()->query("coin")<300)
   return notify_fail("�@�i���n�T�դ���.. �A���������C\n");
  write(HIY"�A�I�F300��, �Ⲽ�����F�A�@�i���C\n"NOR);
  me->set_temp("ticket",1);
  this_player()->add("coin",-300);
  return 1;
 }
 return notify_fail("�o�̥u�沼(Ticket)��C\n");
}