// update 27/12
#include <ansi.h>   
inherit ROOM;
void create()
{
	set("short", HIC"ST�DCakeMaster�ISteps"NOR); 
	set("long", @LONG     
�o�̬O�@���ܦ��W���J�|���A�o�̽檺�J�|�Q���n�Y�C�ӥB��{�b�w
�g�O�g���ĥ|�N�A���v�y�[�A�p�и̧�ǥX�J�|�������C��ѩ����
�@�Ӿ���ʪ���A�ҥH�@�찲��N���ܦh�ȤH�ӶR�J�|�A�ӥB�f���c�h�A
�i�H�ۤv�ոաC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dst12",
]));
  set("objects",([
 __DIR__"npc/sword":1,
 ]));
set("light",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
 add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "�p��") 
                   return 0;
        else {
                   message_vision(HIW"$N���}�F���i�F�p�СC\n\n"NOR ,me);
                   me->move(__DIR__"cakeshop2");
                   tell_room(environment(me),me->query("name")+"���F�L�ӡC",me);
           return 1;
                 }
}