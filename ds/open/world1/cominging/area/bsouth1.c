inherit MOBROOM;
void create()
{
	set("short", "�B�F���n�j��_");
	set("long",@LONG
�o�̬O�B�F���n��j�󪺤��������A�b�o�̦��\�h�L�ȡA�]���\�h
�ӤH�q��æ�~�a�ұa�^���_�����~�A�b�F�観�@�a���\�A���G�̭��ҽ�
���������G�������ˤl�A���O�ݰ_�ӫo���I�����A�j���b�o����@�a��
�Ӧ��W�A�]�i��O�]���O�s�}���A�ҥH�èS���H�|�h�S�O�`�N�o�Ӧa��
�A�_��O���B�F���������s���C
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth.c",
  "east" : __DIR__"bhorse.c",
  "south" : __DIR__"bsouth2.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
 	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}