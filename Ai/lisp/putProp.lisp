(defun putprop (object value property)
    (setf (get object property) value))

(setq obj 'person)

(putprop obj 'Abir 'name)
(putprop obj '24 'age)
(putprop obj '5.5feet 'height)

(setq n (get obj 'name))
(format t "The name of ~a is: ~a~%" obj n)

(setq a (get obj 'age))
(format t "The age of ~a is: ~a~%" obj a)

(setq h (get obj 'height))
(format t "The height of ~a is: ~a~%" obj h)