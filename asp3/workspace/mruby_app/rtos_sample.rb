begin
    n = 10
    #����I�[�o�w�b�h�̑���
    startu  = RTOS.usec
    n.times{
        RTOS.usec
    }
    endu  = RTOS.usec
    overhead = (endu - startu) / (n + 1)

    a=[*1..10]
    sum = 0
    #����J�n
    startu = RTOS.usec
    a.each{|num|
        sum = sum + num
    }
    #����I��
    endu = RTOS.usec

    puts "sum = #{sum}"
    puts "#{endu - startu - overhead} usec"

rescue => e
    puts e
end