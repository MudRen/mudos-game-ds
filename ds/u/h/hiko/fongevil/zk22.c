inherit ROOM;
void create()
{
        set("short", "�s�^�f");
        set("long",@LONG
�o�̬ݰ_�ӤQ�����ˡA�A���e�i�K�O�H�٪��ø����F�A���H�@�Ǯ`
�Ȫ��ˤl�A�åB�����j�ʯ󸭪�����n�����s��A�ϧA�߸̤�򪺡A�o
�̴X�G�O�L�H����A�ӥB�V���e�Pı�N�V�j�P�A�N�s�ѤW���Q�~��s�]
�O�H���ΪA�A�Ӳ��e�X�{�T���p���A�O�A�����ө����Ӥ�V�e�i�C
LONG
        );
  
set("exits", ([
  "north" : __DIR__"zk1",
  "northwest" : __DIR__"zk2",
  "northeast" : __DIR__"zk19",
  "southdown" : __DIR__"mu10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}



