#include <weapon.h>
inherit ROOM;

void create()
{

set("short","�j����");
set("long", @LONG
���a�O����������n�a�I, �]���o�̥��O�j����Ҧb�a, �ǻ��o�ʤj
���즳�ܯ��_���O�q, �C����̪��H�ͯf, �u�n�V�o�ʤj����ۤ�ë�i,
�N�|���v�Ө|, �]�]�����̪��H�ܬݭ��o�ʤj����, �ҥH�P�򦳤��֪��x
�L�b����, ���A�L�k�a��j����.
LONG
);
set("outdoors", "land");
     
set("light",1);
set("exits", ([ 
       "east" : __DIR__"road_1.c",       
   ]));
 set("item_desc",([
        "����":"�@������S���S�j���j����G�i�H(jump)�C\n",
        ]) );
set("no_clean_up", 0);
set("objects",([
__DIR__"npc/garrison_1.c" : 3,
       ]) );
       
setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
       me=this_player();
        if (!arg || arg!="����" ) return 0;
        message_vision("$N�I�i���Z�����\\,���W�F�j����C\n",me);
        me->move(__DIR__"lll");
        tell_room(environment(me),me->query("name")+"���M���@�ӤH���F�W�ӡC\n",me);
        return 1;
}

