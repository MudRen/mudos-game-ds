inherit NPC;

void create()
{
        set_name("���Q�f",({"bi songbo","songbo"}) );
        set("long",@LONG
���Q�f�O�ʾ]�����W���j�̤l�A�ѩ�q�p��b�ʾ]�p���W�A��z��@
��H�٨ӱo�j���A���Q�f���o���j�T���A�@�i��r�y�W���ۥR���۫H����
���A�O�ʾ]����@�N�ӻ������W���̤l�A�X��O�U���x�����~�ӤH�C���L
�L�o�����D�ӨӡA��o�M�ʾ]�������������H���D�[�A�����O����n�ơC
LONG
);
        set("age",30);
        set("race","�H��");
        set("level",30);
        set("attitude", "peaceful");
        set("title","�ʾ]���̤l");
        set("chat_chance",10);
        set("chat_msg",({
                "���Q�f�t�ۤ⨫�Ө��h�A���G�~������....\n",
                (:command("sigh"):),
        }) );
        set("gender", "�k��" );
        set("inquiry", ([
                "�~������" : "���r...�ʦ~�j�T�Ƥw�g���b���e�F�A�ګ�ण�~�ߩO�C",
                "�j�T��"   : "�U�c�����u�ѧ��v��ƤQ�~�Q�a�v�ұѤ���A�a�����ðέʾ]�s���B�A������ɷ|�A�X�Ӱ��^�C",
                "�ѧ�"     : "�u�ѧ��v���ѤѤU�U�����c��Q�Ҿ��E�Ӧ������]�A�H�߶V�c�A�����V�j�A�ݥL�˺Ǵ_�X�A��O���i���B�C",
		"�ð�"     : "�ڭ̤Ѿ]���M�H���D�[�w�g�j���H���o�ƤQ�~���J�ӧ�M�A�Ʊ�ভ�@�B�X�L���ˤ��ڡA�@�|�ѨM���׮`�C"
        ]) );

        setup();
        receive_money(500);
        carry_object(__DIR__"wp/mist-tough_whip")->wield();
        carry_object(__DIR__"eq/mist-jade")->wear();
        carry_object(__DIR__"eq/green-pants")->wear();
        carry_object(__DIR__"eq/bigloves")->wear();

}




int accept_object(object who,object ob)
{
        object powder;

        if(!ob->id("_SILK_CLOTH_") ) {
             return 0;
        }
  
        destruct(ob);
        message_vision("$N���F$n�@�����S�C\n",who, this_object() );
        command("say �o...�o�i���O���p�j�����S�ܡH");
        command("thank "+who->query("id"));
        command("say �D�`���§A�������A���ڭ̯�y��۫䤧�W�A�o�Ӱ����N�e���A�F�a�C");
        powder=new(__DIR__"obj/powder");
        powder->move(who);
        return 1;
}


