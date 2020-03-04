// Room: /d/death/inn1.c
 
inherit ROOM;
 
int do_stuff(object ob);
 
void create()
{
        set("short", "�p��");
        set("long", @LONG
�A�@�i�ӴN�o�{�θ̲��`���ŷx, �𨤾��l�̷L�z�������N�A
���v�l��g�b�ﭱ����W. �X�ӤH�v(shadows)��b�l�Ǥ����b�Q
�רǤ���. �Τ����X�i���, ��, ��W���F�X�T�r�e, �@���ݨӫD
�`���ԩM���R, �A�X�G�ѤF�ۤv���b��B.
 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/death/road1",
]));
 
        set("item_desc", ([
        "shadows" : @SHADOWS
�q�A������m������O�X���X�ӤH���e��, �|�өܵ۶¤潴���H�׾a�b��
�l�䪺����, �����ǨӨ䤤�X�H���ܪ��n��, ���L�q�o�ӶZ���A�L�kť��
�L�̰Q�ת����e. ��A�٦b�Ҽ{�n���n�a�L�h�@�I��, �䤤�@�H�^�Y�ݤF
�A�@��, �A�h��F... ���H... ���H......... �~�M���o��A�@�Ҥ@��!
SHADOWS
        ]) );
        setup();
//        replace_program(ROOM);
}
 
void init()
{
        add_action("redirect_ask","ask");
}
 
int redirect_ask(string str)
{
        object ob;
        string name, tmp1, tmp2;
        ob = this_player();
        name=(string)ob->query("id");
	if (!str) return 0;
        if (sscanf(str,"%s about %s",tmp1, tmp2) == 2) {
                if (tmp1 == name && tmp2 =="�^�a") 
                        return do_stuff(ob);
                        else return 0;
        }
        else return 0;
        return 0;
}
 
int do_stuff(object ob)
{
        write("�A���W�e�h, �C�n���V���Ӫ��o��A�@�˪��H�߰ݦ^�a����.\n");
        tell_room(environment(ob),(string)ob->query("name")+
        "�����l�����h, �M�@�s�¼v�몺�H�������F�Ǥ���.\n",
        ({this_object(), ob}));
        tell_room(environment(ob),
        "�@�w�����\\��"+(string)ob->query("name")+"���M�����F.\n",
        ({this_object(), ob}));
        write("���H�@�y�ܤ]�����N���A�o�伲�L��, �A���e�@�}��....\n");
	ob->reincarnate();
        ob->move("/d/snow/temple");
        message("vision",
                "�A���M�o�{�e���h�F�@�ӤH�v�M���L���H�v�S�n���w�g�b����\n"+
                "�ܤ[�F�M�u�O�A�@���S�oı�C\n", environment(ob), ob);
        return 1;
}
