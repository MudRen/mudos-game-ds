inherit ROOM;

void create()
{
        set("short", "�îѻ�");
        set("light",1);
        set("long", @LONG
�o�̬O���Z�Ъ��øg�աA�|�P�O�@�d�d�ﺡ�Ѫ��j���d�A�Ů𤤥R��
�F�ѭ��𮧡A�b���d�Ǧ��Ӽӱ�A���ⰼ�o���F�@�ǪZ�v�A�ݨӬO�����H
�N�W���[�ݡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"corridor",
    ]));
    set("objects",([
            __DIR__"npc/guard2.c" : 2,
    ]));
        set("no_clean_up", 0);
set("item_desc", ([
 "���d" : "�A�J�Ӫ��@�F�@���d�A�o�{���d�W�\\�۳\\�h�����y�A�٦��@���ѦW�s�u���ѡv�A�γ\\�i�H�ݬ�(look)�C\n",
 "�ӱ�" : "�ݳo�ӱ�V�ݶV�n�_�A�b�ӱ�W�Y��������ƪ��A�G�ǤS���H�ݦu�A�u�n�����N�N(sneak)�W�h�F�C\n",
       "����" : "\n�A�H�N½�}�F�u���ѡv�o���ѡA�o�{�W�Y�g���o�Ǧr�G\n\n"
                  "�i���_�˪L�j- ���B�O�������a�A���ѫ��F�n��A���]���Ǿ��󦹡A���L���a���H�A�`�J��u��\n"
                  "              ����v�A���F�T�ѤT�]���L�k��X�A�צܺ�h�O�ɦӦ��C\n"
                  "              �ǩ󦹦]�A���Z�Ь��X�ƦW�@�k�M���{�e���٧����]�A�ܤ��w�L�F�T�~�A�o�|�W�@�k\n"
                  "              �β��Ю{�o���T���L�A���w�G�D�T���C\n\n"
                  "�i�խߦa���j- ���a�O�����Ю{���j����A�����Ю{�ðΦb���w�[�A�o�l�׵L�q�o�������B�A�]\n"
                  "              �~�����H�A�����ӫͰ��L�s�A�L�q�d�_�C�����Ю{���H�L�ơA�������C\n\n"
                  " �i���s��j - �o�O��L�j�s�����I�A���u�B�F���v�񭥡C��L�j�s�T�]�۱��A����x����b����\n"
                  "              �A�ɱ`�v��鲳�j�x�B�F���A�B�P�x�L�޵o�j�p�ԨơA�]��L�j�s�H�Ʋ��h�A��O��\n"
                  "              �p�A�B�]��a����P�~�ڪ��Ԫ��A�Ӳ��󨾽d�A�ӳy����L�j�s�դO�麥���j�A���Q\n"
                  "              �@��C\n\n",
      ]));
        setup();
}
void init()
{
        add_action("do_sneak","sneak");
}
int do_sneak(string arg)
{
        object me;
        me=this_player();
        if(arg != "�ӱ�") return notify_fail("�A�n�����N�N���V���H\n");
        else {
            tell_object(me,"�A�����N�N���V�ӱ訫�h�C\n");
            me->move(__DIR__"library2f.c");
        }
        return 1;
}
