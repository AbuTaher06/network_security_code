;; (format t "Enter the sides of the triangle: ")

;; (setq a (read))
;; (setq b (read))
;; (setq c (read))

;; (setq s (/ (+ a b c) 2))
;; (setq area (sqrt (* s (- s a) (- s b) (- s c))))

;; (format t "Triangle Area: ~,2f~%" area)

(let ((b (read))       
      (h (read))      
      (area 0))       
  (format t "Enter base and height: ")
  (setq area (* 0.5 b h))  
  (format t "Triangle Area: ~,2f~%" area))  ;; Print area with 2 decimal places
