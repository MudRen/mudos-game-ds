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
 set("exits",(["west":__DIR__"en66",
               "northeast":__DIR__"en63",
               "northwest":__DIR__"en61",
               "north":__DIR__"en62",
               "east":__DIR__"en68",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

