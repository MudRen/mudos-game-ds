#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���T�f");
set("long",@LONG
�A�Ө�T�f�����䤤�@���ж��A�o�̵��H���Pı�������
�A�ݨӬO�ݩ����������H���ж��A�ж��D�H�ӬO�~����j�A
�ӥB�ݨ��Z���o�𶢪��A�Ф�����W�\�ۤ@�M����������A�i
���俳��嶮�C
LONG
    );
 set("objects",([
__DIR__"npc/mountain-man" : 1,
__DIR__"npc/boy-yu" : 1,
]));
set("item_desc", ([
    "����" : "�ΤW�n����Ʃһs�Ӧ��A�ݨӷPı�Q�������C\n",
                 ])); 
set("exits",([
"south":__DIR__"yu_home",
]));
 set("no_kill",1);
 set("no_clean_up",0);
 set("light",1);
 setup();
}             

void reset()
{
  object npc;
  if(objectp(npc = find_living("outboy")))
    if(!npc->query("go_home")) destruct(npc);
  else return;
  ::reset();
  return;
}






