#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG 
�A��J�d�h�Ϫ��P�ɧA�Pı���ʤQ�����K, ���G�ֳQ�d�h
�ҧ]��, �|�B���o�ۨ�󪺯��, ���H�D�`�Q�R. �A�o�{�|�B��
�@�Ǳq�����L�����ΩM�Ӫ�, ���T�g�Ĥj�۵M������.
LONG);
 set("exits",(["north":__DIR__"en64",
               "south":__DIR__"en71",
               "northwest":__DIR__"en63",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

