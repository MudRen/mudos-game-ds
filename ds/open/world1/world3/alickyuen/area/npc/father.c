//updated 12/2
inherit NPC;
void create()
{
        set_name("����",({"god-father","father"}) );
	set("long", "�@�쯫���A�����b�a�W�V�ۯ�����ë�C\n");
        set("age",60);
        set("level",10);
        set("gender","�k");
        set("race","�H��");
        set("chat_chance",10);
        set("chat_msg",({
"�������D�G �ڭ̪��Ѥ��A���A���W���㴭�F\n",
"�������D�G�@�A������{;�@�A�����N�^��b�H���A�p�P�b�ѤW�C\n",
"�������D�G�D�A���ѽ൹�ڭ̤�Ϊ���³�F\n",
"�������D�G�D�A�e���ڭ̪��o�L�A�p�P�ڭ̼e���O�H�@�ˡF\n",
"�������D�G���n���ڭ̳��󻤴b�A���ϧڭ̧K�󤿴c�C\n",
"�������D�G�y�ȩs�K�z\n",
        }) );	
set("talk_reply","��b�ӥi�ȤF.....�٬O�~���ë�n......\n");
        setup();
carry_object(__DIR__"obj/note_book");
}
