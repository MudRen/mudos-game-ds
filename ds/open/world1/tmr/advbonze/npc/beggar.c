inherit NPC;

void create()
{
          set_name("�^��",({ "beggar" }) );
          set("long",@LONG
                                                                                
            [30;47m��    [0m��                                                            
         [30;47m��          [0m��                                                         
         [47m  [43m�k����[33;47m�f   [0m��                                                        
         �� [43m [30m�v[37m\  [47m    [0m��                                                        
      ��[47m [0m��  [30;43m��[36m����[41m [46m [37m�� [0m[36m��[0m                                                      
       [33m��[43m [36;40m��[30;46m��     [43m= [46m�v   [0m 
LONG
        );

        set("race","�H��");
        set("gender","�k��");
        set("chat_chance",10);
        set("chat_msg",({
                (:command("get all"): ),
        }) );
        set("age",30);
        set("level",5);
        set("attitude", "heroism");  
        setup();
}

