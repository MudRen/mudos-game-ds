inherit ROOM;

void create()
{
          set("short", "�����ȩ�");
          set("long", @LONG
�o�O�@������f�̪񪺮ȩ��A�]�]���`�`���F�L�����ȫȡB����B
����A�i���O�����H���A�@������A���]�]���H�߼s��A�b�o�̥i�H��
��\�h�����C�ȩ����f���F�i��s�۵P�A�@�ˤl�A�]��O���v�[���F�C
LONG
          );
        set("exits", ([ /* 1 element(s) */
                "west" : __DIR__"map_14_16",
        ]));

        set("valid_startroom", 1);
        set("objects",([
        __DIR__"npc/waiter":1,
          "/obj/statue":1,
        ]));
        set("no_fight", 1);
        setup();
}

