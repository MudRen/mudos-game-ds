#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIR"����"NOR);
    set("long",@LONG
���t���p�Ѩ����@���Q�H�ҿ�Ѫ��p�ж��A�ж����j�����w�����h
�V�A�Τ��}�ꤣ���A�s�i���㪺�Ȥl�]�䤣��A�u���@���ѹ��j�n�j�\
���b�ж�����B�ö]�A�֪��ɭԴN�]��谽�Ӫ��ŹT�e��ٵۡAť�۪�
�~�������ҵo�X���M�M���n�A�@�I�ܺ������ˤl�C
LONG);
    set("exits",([
        "wiz":"/d/wiz/hall1",
        "west"   : __DIR__"workroom2",
     ]));
    set("light", 1);
    setup();
}
