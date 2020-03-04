// Room: /open/world1/tmr/frost/temple.c

inherit ROOM;

void create()
{
        set("short", "�H���D�[-�����f");
        set("long", @LONG
�A�����b�H���D�[�������f�A�D�[�y�է����Ӧ۵M�A���ئb�s�L�����A
�o�@�I�]�S�ٻ��ܥD�����X�ʾ]�p�s�L�����A�����O�M�j�۵M�ĦX�b�@�_��
���o�X�����P�C�D�[�����Ѭ�����s���A���f���G�Ӥp�D�������ۥ����C
���n�O�@�y���q�J������A���H��L�ƴ��A���`�����B���_���Pı�C
LONG
        );
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/taoist-child" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"temple1",
  "west" : __DIR__"hill1",
  "south" : "/open/world1/tmr/endless/enter",
]));
        set("outdoors", "forest");
        set("current_light", 3);

        setup();
        replace_program(ROOM);
}

