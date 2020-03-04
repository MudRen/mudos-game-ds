// Room: /u/l/luky/room/pearl_5.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIG"�ï]�n��"NOR);
set("long", @LONG

�ġġġġġġ� �A���_��O�@�j���զ����A�W���ġġġġġġ�
"  .   -       ���O��a���ൣ�ҵe����~�C���F     -  '    "
:      -       �O�����F�n���A�����ƨӰ}�}��     -    "  :
= ."   -       �H�������C                         -       =
==-  " -       -                          -       - .   -==
�ááááááááááááá� �áááááááááááááá�
LONG
);
set("exits", ([ /* �X�f */
"west" : __DIR__"pearl_6",
"east" : __DIR__"pearl_4",
]));
set("item_desc",([ //����
  "wall":"��W���F�e���~�ټg�F�X�ӥj��(words)�C\n",
  "����":"��W���F�e���~�ټg�F�X�ӥj��(words)�C\n",
  "words":"�A�i�H�յ�ŪŪ��(read words)�C\n",
  "�j��":"�A�i�H�յ�ŪŪ��(read words)�C\n",
]));
set("objects",([
__DIR__"npc/paintboy":1,
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
 object me;
 int pass_num;
 me = this_player();
 pass_num = random(9999);
 if( !arg || (arg != "words"))return notify_fail("�A�nŪ����?\n");
  else 
   if(random((int)me->query("int"))<20)
    message_vision("$N�ݤF����b�Ѥ]�S������o�{�C(�i��O�Ӳ¤F)\n",me);
   else
   {
    message_vision("$N�ݤF�@�U����A�o�{�W���g�F�@�ǼƦr�C\n",me);
    write("��.. ���ӬO["+pass_num+"]�C\n");
    me->set_temp("pass_num",pass_num);
   }
 return 1;
}
