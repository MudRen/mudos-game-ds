inherit ROOM;
void create()
{
	set("short", "�d�i");
        set("long", @LONG
����o�̬M�J��î���O�@��j�j�p�p���Ƚc�l�A��W���ۤ@�ǷG
�����o�e�M�@�i��g�����ت�C��Ӧa�賣�O�ǹЩM�j����A�O�H�P
ı���I�I�l�x���C
	====================================================
	�d�ߦs�f 	<list> <list wp> <list eq>
	�R�F�� 		<buy ���~> <buy �ƶq ���~>
	��F�� 		<sell ���~> <sell all> <sell �ƶq ���~>
	�եΪF�� 	<try ���~>
	====================================================
LONG
);
	set("exits",([
	"east" : __DIR__"map_12_12",
	"south" : __DIR__"map_13_11",
	"north" : __DIR__"map_11_11",
	]));
	set("objects",([
		__DIR__"../npc/malo_shoper_19": 1,
	]));
	set("no_kill",1);
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

*/