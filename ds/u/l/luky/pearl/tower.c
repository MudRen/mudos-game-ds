// This is a room made by roommaker.

inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
�A���i�𪺤����~���D�o�O�@�y�M�������������j��C�����O�����~����
�H���������A�ǻ����������ө����M�R�n�M���A���O�ʮ�o�Q�������z�A�@��
�S��F͢�A�Ҧ����ͪ����N���{���H�Q�����E�T�C�o�̦��@�i�j��l�A�W����
�F�@�ǲ����Ϊ��k���A��n�訤���������۶���i�H�q���W�@�h�ӡC   
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
]));
set("exits", ([ 
  "east" : __DIR__"sea5",
  "up" : __DIR__"tower2",
]));
set("light",1);
set("no_clean_up", 0);
setup();
 load_object(__DIR__"sand1");
 load_object(__DIR__"sand2");
}
