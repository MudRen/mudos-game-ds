// Room: /u/s/sonicct/area/shop1.c

inherit ROOM;

void create()
{
        set("short", "�s�a");
        set("long", @LONG
�o�O�@��Naboo���W���s�a�A�@��]�ߴN���ܦh�H�ӳܰs���C
�A�����o�{�o�̦��ܦh�W�H�X�J�A�o�̬O�ܦh�O�̯d�s�o�̡C��
�A�i�H�q�s�O�f���o��@�Ǳ����C
LONG
        );
        set("no_clean_up", 0);
             set("light",1);
set("item_desc",(["�s�d":"�o�O�@�ө�s���s�d�C\n",]));  

        setup();
        replace_program(ROOM);
}
void init()
{
        add_action("typepush","push");
}
int typepush(string arg)
{
        object me;
        me=this_player();
        if (arg != "�s�d") return 0;
        
        message_vision("�u���A��@���A�K�s�H�a�d���t�@�өж��̡C\n\n" ,me);
        me->move("/u/a/alickyuen/area/bar2");
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�C\n",me);
        return 1;
}


