inherit MOBROOM;
void create()
{
        set("short", "�s�y");
        set("long",@LONG
�o�̬O������s�y���a��A�D���즹���M���ǭׯ�L�A�]�\����
�H�~��󦹡A�D����������C�G�A�A�ݨӸӬO���H�M�z�L������A�ϧA
��[�T�H�o�̦��H��A�F�_�䦳�@�������b�s�y�A��n�h�O���s�U�C
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"mu12",
  "southwest" : __DIR__"mu4",
]));
        set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/bee",
}) );
set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 






