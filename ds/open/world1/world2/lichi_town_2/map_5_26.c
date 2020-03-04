inherit ROOM;
void create()
{
	set("short", "���]�j�U");
        set("long", @LONG
    �A�����b���s����]�������j�U�C�a�W���ӥ۪O(Slate)�C
LONG
);
	set("exits",([
	"east" : __DIR__"map_5_27",
	"south" : __DIR__"map_6_26",
	"north" : __DIR__"map_4_26",
	"west" : __DIR__"map_5_25",
     "down" : "/open/world2/shengsan/aovandis/room103",  // add by wilred
	]));
	set("light",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	set("hide_item_desc",([	
	"slate" : @SLATE1
�@���^�b�a�W���۪O�A�W����ۤ@�ǹϤ�C

        �y�i�@�i�i�i�i���i�i�i�i�i�i�i�@�@�@�@�i�i���k�����Ϩ�:
        �y�i�i�i�i�i�i�i�i�i�k�i�k�i�i�i�@���@�i�@�@�k
        �y�i�i�i�i�i�i�i�i�i�@�@�@�i�i���@�@�@�i�i�i�k��  �A�ثe����m
        �y�i�i�i�i�i�i�i�i���@��e�i�i�i�@�@�@�i�@�@�k��  ��L���a
        �y�i�i�i�i�i�i�i�i�i�@�@�@�i�i�@�@�@�@�i�i�@�k��  �X�J�f
        �y�i�i�i�i�i�i�i�i�i�k�i�k�i�i�@�@���@�i���@�k�e  �d�i
        �y�i�i�i�i�i�i�i�i�i�i�i�i�i�i�@�@�@�@�i�i�@�k�k  ��

SLATE1,
	])	);
	set("item_desc",([	
	"�۪O" : @SLATE2
�@���^�b�a�W���۪O�A�W����ۤ@�ǹϤ�C

        �y�i�@�i�i�i�i���i�i�i�i�i�i�i�@�@�@�@�i�i���k�����Ϩ�:
        �y�i�i�i�i�i�i�i�i�i�k�i�k�i�i�i�@���@�i�@�@�k
        �y�i�i�i�i�i�i�i�i�i�@�@�@�i�i���@�@�@�i�i�i�k��  �A�ثe����m
        �y�i�i�i�i�i�i�i�i���@��e�i�i�i�@�@�@�i�@�@�k��  ��L���a
        �y�i�i�i�i�i�i�i�i�i�@�@�@�i�i�@�@�@�@�i�i�@�k��  �X�J�f
        �y�i�i�i�i�i�i�i�i�i�k�i�k�i�i�@�@���@�i���@�k�e  �d�i
        �y�i�i�i�i�i�i�i�i�i�i�i�i�i�i�@�@�@�@�i�i�@�k�k  ��

SLATE2,
	])	);
        setup();
        call_other("/obj/board/now_malo_b", "???");
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

void init()
{
  this_player()->set_temp("now_new_city",1);
  this_player()->set_temp("now_old_city",);
}
