inherit ROOM;
void create()
{
        set("short","�۶�");
        set("long",@LONG
�A���b���~���۶��A�A�����e�N�O���A���~�𪺹��ˮݮݦp��
�A�Q���O�Ѻ�諸�J��v�һs�A�ӤW�����j��o�Ƭ�����A���ӬO�w�g��
�ǡA�ӿ��J�f�o�Ƭ�����A�F�����@�ӥۥx�A�譱�h�O�@�ӪŦa�A�F�_
�M�F�n�U���@���p�D�C
LONG
        );
  
set("exits", ([
  "east" : __DIR__"zk20",
  "west" : __DIR__"zk4",
  "northeast" : __DIR__"zk8",
  "southeast" : __DIR__"zk10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



