inherit NPC;

void create()
{
        set_name("�q�u�u�Y", ({ "mine leader","leader" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",15);
        set("age",41);
        set("evil",-10);
        set("long",@LONG
�t�d�ʤu���q�u�u�Y�A���M�~�L�|�Q�A���O�]���������Ұ�
�u�@�A�m�N�F�۷�n�����A�|�Q���̵M�O�@�����s�A�Ҧ�
���q�u�̳��ܴL�q�L�C
LONG
);
        set("chat_chance",5); 
        set("chat_msg",({
                (:command("addoil"):),
                "�u�Y�j�n�۹D�G�u�j�a��O�F����~~~�v\n",
        }) );
        setup();
        add_money("coin", 100); 
}
