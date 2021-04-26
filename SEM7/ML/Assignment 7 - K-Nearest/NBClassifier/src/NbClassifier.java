import weka.core.Instances;
import weka.classifiers.Evaluation;
import weka.classifiers.bayes.NaiveBayes;
import java.io.BufferedReader;
import java.io.FileReader;
import java.lang.Exception;

public class NbClassifier {
  public static void main(String[] args) {
    // NbClassifier nb = new NbClassifier();
    try {
      BufferedReader br1 = null;
      br1 = new BufferedReader(new FileReader("Datasets/IDSTr.arff"));
      BufferedReader br2 = null;
      br2 = new BufferedReader(new FileReader("Datasets/IDSTest.arff"));

      Instances train = new Instances(br1);
      Instances test = new Instances(br2);

      train.setClassIndex(train.numAttributes() - 1);
      test.setClassIndex(test.numAttributes() - 1);

      // System.out.println("Training data: /n/n" +train);
      // System.out.println("Test data: /n/n"+test);

      NaiveBayes nB = new NaiveBayes();
      nB.buildClassifier(train);
      System.out.println("Naive Bayes Model :\n\n\n" + nB);

      Evaluation eval = new Evaluation(test);
      eval.evaluateModel(nB, test);

      System.out.println("\nError Rate is :" + eval.errorRate());
      System.out.println("\nAccuracy is :" + (1 - eval.errorRate()));

      System.out.println("Precision" + " " + "Recall" + " " + "Fmeasure");
      for (int i = 0; i < test.numClasses(); i++) {
        System.out.println(eval.precision(i) + " " + eval.recall(i) + " " + eval.fMeasure(i));
      }
    } catch (Exception e) {
      System.err.println(e.getMessage());
    }
  }
}
