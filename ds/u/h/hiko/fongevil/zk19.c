inherit ROOM;
void create()
{
        set("short", "�s���p��");
        set("long",@LONG
�o�̬ݰ_�ӤQ�����ˡA�������O�@�ǵL�D���t�X�A�ݥB�s�����n�Q����
�F�A�O�Ať�ӥͬȡA�o�̥|�B��h���L�L���A�Pı�����N�M�A�ϧA���e����
���N�@�]�j���ʷn�A���F�n��i�ݨ�@���p�|�C
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk18",
  "southwest" : __DIR__"zk22",
  ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 


