inherit NPC;

void create()
{
        set_name("�Q��",({"Salt maker","maker"}) );
        set("long",@LONG
�q�ƻs�Q�u�@�������A�s�Q�O�����ܭ��n�����J�ӷ��A�b�@�~��
���̥R���A�B�q�̤֪��ɸ`���A�������|��J�H�O�q�ƻs�Q�C
LONG);
        set("race","�H��");
        set("gender", "�k��");  
        set("age",35);
        set("level",19);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
        "�Q���y�ۤ�j�������A���Ԧa�����Q�ɡC\n",
        "�Q�����U�ӵy�@�𮧡A�Φ��y���ۦ��C\n",
        }));
        setup();
        add_money("coin",350);
}

void die()
 {
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 
        switch( random(99) ) {
        case  0..19: new(__DIR__"eq/leather-gloves")->move(this_object());
        break;}
        ::die();
        return;
 }
