inherit ROOM;
void create()
{
        set("short","�۶�");
        set("long",@LONG
�A���b���~���۶��A�A�����e�N�O���A���~�𪺹��ˮݮݦp��
�A�Q���O�Ѻ�諸�J��v�һs�A�ӤW�����j��o�Ƭ�����A���ӬO�w�g��
�ǡA�ӿ��J�f�o�Ƭ�����A�譱���@�ӥۥx�A�F���h�O�@���s�L�A��_
�M��n�U���@���p�D�C
LONG
        );
  
set("exits", ([
  "east" : __DIR__"zk17",
  "west" : __DIR__"zk21",
  "northwest" : __DIR__"zk14",
  "southwest" : __DIR__"zk11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




