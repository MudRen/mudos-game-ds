inherit NPC;
void create()
{
        set_name("�i��", ({"MR. Cheng","mr","cheng"}) );
        set("long",@LONG
�L�O�@��h�𪺤��ȤH���A�b�X�~�e�d�l�L�u�H��A�b�L���y�W�û���
�����S�X�s�˪����C
LONG);
        set("gender","�k��");        
        set("race", "human");
        set("age", 70);
        set("level",40);
        set("dex",30);
        set("talk_reply","�O�ӷЧڡI���j�ݤ߱����n�A���ںu�I\n");
        set("chat_chance",10);
        set("chat_msg",({
        (: command("say ���I�u��......�C\n", ):),
        (: command("say �ګ��|�o�򤣤p�ߩO�I�H\n"):),
        (: command("say ����Q�����F��......�C\n"):),
        (: command("say ���I�����D�N���n�h�����F�C \n"):),
        (: command("say ���F����[���F��A���F�ڳ��M�S�o�{�C\n"):),
        (: command("sigh"):),
        (: command("walk"):),
        }) );        
        setup();
}
