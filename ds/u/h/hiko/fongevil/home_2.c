#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���T�f");
set("long",@LONG
�A�Ө�T�f�����䤤�@���ж��A�o�̬ݨӦ��G�O�ݩ�ĵ�
���ж��A�i�H����X�ˤp�����M�@�ǫĤl�Ϊ�����A�Q�ӸӬO
�o�a�H���ĵ����a��C
LONG
    );
 set("exits",([
"east":__DIR__"yu_home",
]));
 set("item_desc", ([
  "����" : "�Τ��Y�M�@��÷�l�s���A�O�ĵ��R�����p�����C\n",
 ])); set("no_clean_up",0);
 set("light",1);
 setup();
}             




