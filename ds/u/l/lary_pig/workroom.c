inherit ROOM;

void create()
{
        set("short", "���|�p���M�h��");
        set("long", @LONG
�o�̬O���|�p�����ꪺ�Ӯa�M�h�Ϊ��`���A�ͬ��b�o�̪��M�h��
�A�H�H�������R���ۥ��q�θt�䪺�O�q�A�ӥL�̶W�H�����ʤO�αj�j
���}�a�O�A�]�ϱo�L�̦������|�p�����L�׬O��~���Ԫ��άO�鷺��
���u�A�ҬO�̱j�������D�O�A���M�h�̩ҫH�����M�奄�۩M�ˤv���H
���u�M�h�D�믫�v�]�Ϫ��Ӯa�M�h�Ϊ��C�@�즨���A�p�׬O�b��B�A
�ҬO�����j�a�L�����@�s�A�P�ɤ]�O���|�p�����ꤺ���֦~�̤ߥؤ�
�z�Q���ؼСC�b�o�Ӯa�M�h���`������W�A���ۤ@�ⰵ���M�h���W�L
�Q�H�x���Ӫ̤��C�C�p�G�A�Q�[�J�A�æ����ڭ̤������@���A�A�i�H
�yJoin�z�A�Ϊ̬O�yhelp guild�z�ӤF�ѧڭ̡C
LONG
        );

        set("exits", ([
  "east" : "/u/l/lary/kni2",
 "west" : "/u/l/lary/kni3",
        ]) );
        set("light",1);
        setup();
        call_other( "/obj/board/lary_b.c", "???" );


}
