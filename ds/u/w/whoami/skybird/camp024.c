inherit ROOM;

void create()
{
        set("short", "�j�b");
        set("long", @LONG
���M�O��x��b�A���O�Q���ξA���s�A�a�W�Q�۫p�p���A��
�A�b�O�|�P���_�س��Τ�ֺ��a�]�q�_�ӡA��Ѫ��H���@���]
���|�j�i�ӡC�b�O���@����ۤ@�i�j�ɡA���i�H����ӤH�w�ΡA
�b�O���t�@���ۤ@�i�Q����A�����\�ۨ��Ȥl�A��l�W�\
�ۤ@�M�������A�Ӧb�b�O���ߩ�ۤ@�Ӻ륩��Ϊ��ɤ��l�A�{
�b�W����ۤ@���}���A�ϱo��ӱb�O���O�x�v�v���C  
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"camp020",
]));
 set("objects", ([
       __DIR__"mob/general" : 1,
                ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

