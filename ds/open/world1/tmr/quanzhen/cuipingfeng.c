// cuipingfeng.c �A�̮p��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�A�̮p��");
        set("long", @LONG
�o�̬O�A�̮p���p���C�A�̮p�O�׫n�s���Ĥ@�p�A�]�O�̸G���@
�Ӥs�p�C�a�V��ئ��@�Ӥp�F�l�A�A���i�F�����d����A���B���s��
�ն��}�B·¶�A�n���׿v�ۤ���ؿv�A�s���M�R�A�i���Q�ն��ɾB��
�F�C�X�ӹC�Ȥ]�b�F�����}�A���ɹ��g���ۦ��a�����C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"baishulin3",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

	set("coor/x", -3140);
	set("coor/y", 50);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}