#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"�h�A"NOR);
        set ("long", @LONG
�z!�A²�������۫H�A�ۤv�������A�o���h�A�ٯu
�j���A²���i�H�δ�ӧήe�C�A�V�h�A�̱�h�A�n��
���ͪ��b���ʡA�i�O�S���ӹ�..�b�n�_�ߪ��X�ϤU�A
�A�@�B�B���V�o���h�A�������a�a�C
LONG);  
        
        set("exits", ([
        "west" : __DIR__"humid2",
        "north" : __DIR__"humid4",
        "south" : __DIR__"humid5",
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
