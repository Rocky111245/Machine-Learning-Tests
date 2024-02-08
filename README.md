# Quadratic Function Approximation with Machine Learning

This repository presents a machine learning model that approximates quadratic relationships, commonly encountered in scientific and economic datasets. The model employs polynomial regression techniques to predict outcomes that follow quadratic patterns.

The project utilizes an initial quadratic equation derived from an Excel plot of the dataset. This baseline equation captures the visible trend in the data. The machine learning model iteratively adjusts its parameters to align its predictions more closely with the actual data.After training, the model yields a quadratic equation based on the optimized weights. The equation is then plotted in Excel to compare it against the curve derived from the initial data. This comparison is crucial to evaluate the model's accuracy in replicating the observed trend.

The documentation below outlines the methodology, testing phases, learning rate adjustments, and the final model convergence. The goal is to showcase the model's capacity to reflect the inherent quadratic relationship within the dataset.

## Data Visualization and Initial Equation

Data preparation involved visualizing the dataset in Excel, where it was clear that a quadratic function could approximate the observed trend. The trendline provided an initial quadratic equation, serving as a reference point for the machine learning model's performance.

## Comparative Analysis and Model Assessment

The machine learning model was assessed by comparing its derived equation to the initial equation from Excel. This process confirms the model's effectiveness in capturing the quadratic behavior within the data.

The sections that follow provide a detailed account of the machine learning model's development, parameter tuning, and outcome analysis.


Prior to these tests, data was prepared and an Excel plot was constructed to visualize the nature of the data. It was evident that the data approximates a quadratic function, as depicted in the plot below. The trendline and its corresponding equation were also derived from the Excel visualization.
![image](https://github.com/Rocky111245/Machine-Learning-Tests/assets/113866147/b4466fbb-dd89-4877-99bd-abc0035995ab)
**Figure 1**: Input data vs Actual Output Quadratic Curve.


The weights \( w1, w2, w3 \) in the learning model correspond to the coefficients \( a, b, c \) of the quadratic equation. Based on the plot, the equation is inferred to be:

\[ y = 1.0066x^2 - 0.1137x + 0.5082 \]

This serves as our baseline for comparison. It's important to note that the data is not a perfect quadratic curve; it contains some noise to better reflect real-world scenarios. The objective is to determine the effectiveness of our model and identify the appropriate learning rate.

## First Test

A learning rate of ( 1e-4 ) was chosen with 100,000 iterations. The cost decreased significantly at first, slowing down as the cost function approached a value of approximately 0.600. This deceleration can be attributed to the "bend" at around \( \pm0.7 \) on the x-axis, where the slope becomes less steep. Consequently, changes in weights have a diminished impact on \( y \). This behavior is termed the 'stagnation point' for descriptive purposes. While the cost reduction isn't completely stagnant, the term reflects the observed trend.

To address this, the learning rate was slightly increased. Nonetheless, an adaptive learning rate might be more effective, especially if the cost reaches a certain threshold (e.g., 0.600), at which point the learning rate would adjust and increase.
![image](https://github.com/Rocky111245/Machine-Learning-Tests/assets/113866147/092ab01b-9bda-445a-b83f-99304a120855)
**Figure 2**: Learning rate of ( 1e-4 ) with 100,000 iterations.

The quadratic equation modeled by this learning rate is:

\[ y = 1.007008x^2 - 0.113120x + 0.508273 \]

## Second Test

A learning rate of ( 1e-3 ) was chosen with 100,000 iterations.
![image](https://github.com/Rocky111245/Machine-Learning-Tests/assets/113866147/976535fc-b4e4-45ca-8087-d017967fb202)
**Figure 3**: Learning rate of \( 1 \times 10^{-3} \) with 100,000 iterations.


The resulting equation is:

\[ y = 1.007031x^2 - 0.113122x + 0.507934 \]

The outcome demonstrates that an adaptive learning rate or bias adjustment may not be necessary, as the model closely approximates the actual equation derived from Excel. The resulting cost is within an acceptable range.

By generating a series of plots with this quadratic equation and comparing them with the actual data plot, it is evident that the training model closely mirrors the actual output of the input data.

| Input         | Actual Output | Experimental Output | Equation from Excel | Equation Derived from Learning Model |
|---------------|---------------|---------------------|---------------------|--------------------------------------|
| -5            | 26.76405235   | 26.249319           | y = 1.0066x^2 - 0.1137x + 0.5082    | y = 1.007031x^2 - 0.113122x + 0.507934 |
| -4.473684211  | 20.41400762   | 21.1685739          |                     |                                      |
| -3.947368421  | 16.56045544   | 16.64574072         |                     |                                      |
| -3.421052632  | 13.94449431   | 12.68081944         |                     |                                      |
| -2.894736842  | 10.24705938   | 9.27381008          |                     |                                      |
| -2.368421053  | 4.632140403   | 6.424712629         |                     |                                      |
| -1.842105263  | 4.343440218   | 4.133527089         |                     |                                      |
| -1.315789474  | 1.579944731   | 2.40025346          |                     |                                      |
| -0.789473684  | 0.520049846   | 1.224891742         |                     |                                      |
| -0.263157895  | 0.47985058    | 0.607441936         |                     |                                      |
| 0.263157895   | 0.213295649   | 0.547904042         |                     |                                      |
| 0.789473684   | 2.077542205   | 1.046278058         |                     |                                      |
| 1.315789474   | 2.492339664   | 2.102563986         |                     |                                      |
| 1.842105263   | 3.515026817   | 3.716761825         |                     |                                      |
| 2.368421053   | 6.053281515   | 5.888871576         |                     |                                      |
| 2.894736842   | 8.713175712   | 8.618893238         |                     |                                      |
| 3.421052632   | 13.19768018   | 11.90682681         |                     |                                      |
| 3.947368421   | 15.37655919   | 15.7526723          |                     |                                      |
| 4.473684211   | 20.32691812   | 20.15642969         |                     |                                      |
| 5             | 24.14590426   | 25.118099           |                     |                                      |


![image](https://github.com/Rocky111245/Machine-Learning-Tests/assets/113866147/a2307d87-0310-4efb-8cd8-f97d2b2aaab0)
**Figure 4**: Comparison of Actual Output Data vs Algorithmically Derived Output.

## Model Performance and Further Improvements

The model has demonstrated commendable performance in fitting the quadratic data, yielding final weights of \( w_1 = 1.007031 \), \( w_2 = -0.113122 \), and \( w_3 = 0.507934 \). With a Mean Squared Error (MSE) of 0.606610, the model's predictive accuracy is high, considering the presence of noise in the real-world data it was trained on.

### Assessment of Current Model:

- **Weights Close to Derived Equation:** The final weights are quite close to those derived from the trendline in Excel, indicating the model's capability to uncover underlying data patterns.
- **Low MSE:** An MSE of around 0.6 suggests that the model's predictions are, on average, close to the actual data points. This level of error is acceptable, especially if the noise in the data is significant.

### Opportunities for Improvement:

Despite the model's strong performance, there's always room for enhancement:

- **Hyperparameter Tuning:** Fine-tuning the learning rate and experimenting with different optimization algorithms could potentially lower the MSE even further.
- **Feature Scaling:** Normalizing or standardizing the input features may lead to better model performance, especially in datasets with a large range of input values.
- **Adaptive Learning Rate:** Implementing an adaptive learning rate that changes over time or in response to the error gradient could help the model converge faster and possibly achieve a lower MSE.
- **Cross-Validation:** Using cross-validation techniques can provide a better assessment of the model's performance on unseen data and help prevent overfitting.
- **Regularization Techniques:** To combat overfitting, especially in more complex or higher-dimensional datasets, regularization methods like L1 or L2 can be applied.

### Concluding Remarks:

The results are promising, showing that the machine learning model is effective in learning quadratic relationships within the data. The MSE indicates a good fit to the data, but as with any machine learning project, there's potential for further refinement to enhance the model's predictive power.



