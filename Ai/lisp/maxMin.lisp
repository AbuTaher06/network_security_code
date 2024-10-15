(defun readNums (n)
  (loop repeat n collect (read)))

(format t "Enter the value of n: ")
(let ((n (read)))  ;; Read n directly in let
  (format t "Enter the numbers: ")
  (let ((nums (readNums n)))  ;; Read numbers in a single expression
    (format t "Maximum: ~a~%" (apply #'max nums))  ;; Find and print max
    (format t "Minimum: ~a~%" (apply #'min nums))))  ;; Find and print min
